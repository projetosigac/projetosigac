CREATE TABLE cadastro_samu
(
	samu_id	int NOT NULL,
	samu_cnes int NOT NULL,
	samu_cnpj char(20) NOT NULL,
	samu_endereco varchar(255),
	samu_qtd_veiculos int,
	samu_qtd_medicos int,
	PRIMARY KEY (samu_id)
)

CREATE TABLE funcionario_samu
(
	func_id int,
	samu_id int,
	funcionario_nome varchar(255),
	funcionario_cargo char(35),
	PRIMARY KEY (func_id),
	FOREIGN KEY (samu_id) REFERENCES cadastro_samu (samu_id)
)