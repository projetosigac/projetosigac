CREATE TABLE `sigac`.`ocorrencia` (
  `id` INT  NOT NULL AUTO_INCREMENT,
  `data_abertura` DATETIME  NOT NULL,
  `status` ENUM('ABERTO', 'FECHADO')  NOT NULL,
  `n_ambulancias_necessarias` INT ,
  `comentarios` TEXT  NOT NULL,
  `n_vitimas` INT  NOT NULL,
  PRIMARY KEY (`id`)
)
ENGINE = InnoDB;


CREATE TABLE cadastro_samu
(
	samu_id	int NOT NULL AUTO_INCREMENT,
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
