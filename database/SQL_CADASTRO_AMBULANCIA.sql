CREATE TABLE cadastro_ambulancia
(	
	amb_id					INT,
	amb_qtd_passageiros		INT,
	amb_tipo				char(2),
	amb_status				varchar(255),
	samu_id					INT,
	PRIMARY KEY(amb_id),
	FOREIGN KEY (samu_id) REFERENCES cadastro_samu(samu_id)
)


create table amb_equipamento
(
	equip_id		INT,
	equip_descricao	varchar(255),
	PRIMARY KEY(equip_id)

)


create table amb_lista_equipamentos
(
	amb_id		INT,
	equip_id	INT,
	FOREIGN KEY (amb_id) REFERENCES cadastro_ambulancia(amb_id),
	FOREIGN KEY (equip_id) REFERENCES amb_equipamento(equip_id)
)