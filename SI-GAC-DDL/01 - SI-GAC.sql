DROP DATABASE IF EXISTS SIGAC;
CREATE DATABASE IF NOT EXISTS SIGAC;
USE SIGAC;

-- Criação da tabela "Estado"
CREATE TABLE estado
(
	est_id			INT				PRIMARY KEY,
	est_nm			CHAR(35)		NOT NULL,
	est_ab			CHAR(02)		NOT NULL
);

-- Criação da tabela "Cidade"
CREATE TABLE cidade
(
	cid_id			INT				PRIMARY KEY,
	cid_nm			CHAR(35)		NOT NULL,
	cid_est_cod		INT,
	CONSTRAINT FK_cid_est_cod FOREIGN KEY (cid_est_cod)
		REFERENCES estado (est_id)
);

-- Criação da tabela "Tipo da Localidade"
CREATE TABLE localidadetipo
(
	lot_id		TINYINT			AUTO_INCREMENT		PRIMARY KEY,
	lot_ds		CHAR(35)	NOT NULL
);

-- Criação da tabela "Localidade"
CREATE TABLE localidade
(
	loc_id				INT		AUTO_INCREMENT	PRIMARY KEY,
	loc_end				CHAR(50)	NOT NULL,
	loc_num				CHAR(10)	NOT NULL,
    loc_bairro			CHAR(35)	NOT NULL,
	loc_cid_cod			INT,
	loc_com				CHAR(50),
	loc_cep				CHAR(08),
	loc_lot_cod			TINYINT,
	CONSTRAINT FK_loc_cid_cod FOREIGN KEY (loc_cid_cod)
		REFERENCES cidade (cid_id),
	CONSTRAINT FK_loc_lot_cod FOREIGN KEY (loc_lot_cod)
		REFERENCES localidadetipo (lot_id)
);

-- Criação da tabela "Estado Civil"
CREATE TABLE ecivil
(
	eci_id			TINYINT		AUTO_INCREMENT		PRIMARY KEY,
	eci_ds			CHAR(15)
);

-- Criação da tabela "Status Pessoa"
CREATE TABLE stpessoa
(
	stp_id			TINYINT		AUTO_INCREMENT		PRIMARY KEY,
	stp_ds			CHAR(15)
);

-- Criação da tabela "Pessoa"
CREATE TABLE pessoa
(
	pes_id				INT				AUTO_INCREMENT		PRIMARY KEY,
	pes_nm				CHAR(50)		NOT NULL,
	pes_sx				BIT				NULL, /* M = 1 e F = 0 */
	pes_dt_nasc			DATE			NOT NULL,
	pes_rg				CHAR(11)		NOT NULL,
    pes_cpf				CHAR(11)		NOT NULL,
    pes_dt_cad			TIMESTAMP		DEFAULT CURRENT_TIMESTAMP,
	pes_loc_cod			INT,
    pes_eci_cod			TINYINT,
    pes_stp_cod			TINYINT,
	CONSTRAINT FK_pes_loc_cod FOREIGN KEY (pes_loc_cod)
		REFERENCES localidade (loc_id),
	CONSTRAINT FK_pes_eci_cod FOREIGN KEY (pes_eci_cod)
		REFERENCES ecivil (eci_id),
	CONSTRAINT FK_pes_stp_cod FOREIGN KEY (pes_stp_cod)
		REFERENCES stpessoa (stp_id)
);

-- Criação da tabela "Crise"
CREATE TABLE crise
(
	cri_id			INT				AUTO_INCREMENT		PRIMARY KEY,
	cri_ds			CHAR(35)		NOT NULL,
    cri_txt			VARCHAR(255),
    cri_cat			ENUM('Preto', 'Vermelho', 'Amarelo')	NOT NULL,
    cri_dt_cad		TIMESTAMP		DEFAULT CURRENT_TIMESTAMP,
    cri_loc_cod		INT,
    CONSTRAINT FK_cri_loc_cod FOREIGN KEY (cri_loc_cod)
		REFERENCES localidade (loc_id)
);

-- Criação da tabela "Telefone"
CREATE TABLE fone
(
	fon_id			TINYINT		AUTO_INCREMENT		PRIMARY KEY,
	fon_num			CHAR(12),
	fon_pes_cod		INT,
	CONSTRAINT FK_fon_pes_cod FOREIGN KEY (fon_pes_cod)
		REFERENCES pessoa (pes_id)
);

-- Criação da tabela "Departamento"
CREATE TABLE departamento
(
	dep_id		TINYINT			AUTO_INCREMENT		PRIMARY KEY,
	dep_nm		CHAR(20)		NOT NULL
);

-- Criação da tabela "Crise Departamento"
CREATE TABLE crise_departamento
(
	crd_id			INT				AUTO_INCREMENT		PRIMARY KEY,
	crd_dep_cod		TINYINT,
    crd_cri_cod		INT,
    CONSTRAINT FK_crd_dep_cod FOREIGN KEY (crd_dep_cod)
		REFERENCES departamento (dep_id),
	CONSTRAINT FK_crd_cri_cod FOREIGN KEY (crd_cri_cod)
		REFERENCES crise (cri_id)
);

-- Criação da tabela "Boletim de Ocorrência"
CREATE TABLE boletim
(
	bol_id				INT				AUTO_INCREMENT		PRIMARY KEY,
	bol_ds				CHAR(20)		NOT NULL,
    bol_dt_fato			DATE			NOT NULL,
    bol_hora_fato		TIME			NOT NULL,
    bol_dt_ini_atend	DATE			NOT NULL,
    bol_hora_ini_atend	TIME			NOT NULL,
    bol_dt_fim_atend	DATE			NOT NULL,
    bol_hora_fim_atend	TIME			NOT NULL,    
    bol_dt_cad			TIMESTAMP		DEFAULT CURRENT_TIMESTAMP,
    bol_pes_cod			INT,
    CONSTRAINT FK_bol_pes_cod FOREIGN KEY (bol_pes_cod)
		REFERENCES pessoa (pes_id)
);

-- Criação da tabela "Histórico do Boletim de Ocorrência"
CREATE TABLE histboletim
(
	his_id			INT				AUTO_INCREMENT		PRIMARY KEY,
	his_ds			VARCHAR(2000)	NOT NULL,
    his_dt_cad		TIMESTAMP		DEFAULT CURRENT_TIMESTAMP,
    his_bol_cod		INT,
    CONSTRAINT FK_his_bol_cod FOREIGN KEY (his_bol_cod)
		REFERENCES boletim (bol_id)
);

-- Criação da tabela "Recursos"
CREATE TABLE recurso
(
	rec_id			INT			AUTO_INCREMENT		PRIMARY KEY,
	rec_nm			CHAR(35)	NOT NULL,
	rec_tipo		CHAR(35)	NULL,
    rec_st			BIT,
    rec_loc_cod		INT,
    rec_dep_cod		TINYINT,
    CONSTRAINT FK_rec_loc_cod FOREIGN KEY (rec_loc_cod)
		REFERENCES localidade (loc_id),
	CONSTRAINT FK_rec_dep_cod FOREIGN KEY (rec_dep_cod)
		REFERENCES departamento (dep_id)
);

-- Criação da tabela "Veículo"
CREATE TABLE veiculo
(
	vei_id			INT			AUTO_INCREMENT		PRIMARY KEY,
    vei_placa		CHAR(07)	NOT NULL,
    vei_desc		CHAR(50)
);

-- Criação da tabela "Veículo Crise"
CREATE TABLE veiculo_crise
(
	vcr_id			INT			AUTO_INCREMENT		PRIMARY KEY,
    vcr_vei_cod		INT,
    vcr_cri_cod		INT,
    CONSTRAINT FK_vcr_vei_cod FOREIGN KEY (vcr_vei_cod)
		REFERENCES veiculo (vei_id),
	CONSTRAINT FK_vcr_cri_cod FOREIGN KEY (vcr_cri_cod)
		REFERENCES crise (cri_id)
);

-- Criação da tabela "Objeto"
CREATE TABLE objeto
(
	obj_id			INT				AUTO_INCREMENT		PRIMARY KEY,
    obj_tipo		CHAR(35)		NOT NULL,
    obj_desc		VARCHAR(255)
);

-- Criação da tabela "Objeto Crise"
CREATE TABLE objeto_crise
(
	obc_id			INT		AUTO_INCREMENT		PRIMARY KEY,
    obc_obj_cod		INT,
    obc_cri_cod		INT,
    CONSTRAINT FK_obc_obj_cod FOREIGN KEY (obc_obj_cod)
		REFERENCES objeto (obj_id),
	CONSTRAINT FK_obc_cri_cod FOREIGN KEY (obc_cri_cod)
		REFERENCES crise (cri_id)
);
