USE SIGAC;

-- Inserção na tabela "Estado"
-- Executar arquivo de carga "02 - estado.sql"
SELECT * FROM estado;


-- Inserção na tabela "Cidade"
-- Executar arquivo de carga "03 - cidade.sql"
SELECT * FROM cidade;


-- Inserção na tabela "Tipo da Localidade"
-- Executar arquivo de carga "04 - localidadetipo.sql"
SELECT * FROM localidadetipo;


-- Inserção na tabela "Localidade"
INSERT INTO localidade (loc_end, loc_num, loc_bairro, loc_cid_cod, loc_lot_cod)
VALUES ('dos Ingleses', '100', 'Jd. Europeu', 5208, 33);

SELECT * FROM localidade;


-- Inserção na tabela "Estado Civil"
-- Executar arquivo de carga "05 - ecivil.sql"
SELECT * FROM ecivil;


-- Inserção na tabela "Status Pessoa"
-- Executar arquivo de carga "06 - statuspessoa.sql"
SELECT * FROM stpessoa;


-- Inserção na tabela "Pessoa"
INSERT INTO pessoa (pes_nm, pes_sx, pes_dt_nasc, pes_rg, pes_cpf, pes_loc_cod, pes_eci_cod, pes_stp_cod)
VALUES ('João José', 1, '2015-09-11', '521779334', '19216810023', 1, 2, 1);

SELECT * FROM pessoa;


-- Inserção na tabela "Crise"
INSERT INTO crise (cri_ds, cri_txt, cri_cat, cri_loc_cod)
VALUES ('Alagamento', 'Alagamento de 80% da cidade', 'Vermelho', 1);

SELECT * FROM crise;


-- Inserção na tabela "Telefone"
INSERT INTO fone (fon_num, fon_pes_cod) VALUES ('956891254', 1);

SELECT * FROM fone;


-- Inserção na tabela "Departamento"
-- Executar arquivo de carga "07 - departamento.sql"
SELECT * FROM departamento;


-- Inserção na tabela "Crise Departamento"
INSERT INTO crise_departamento (crd_dep_cod, crd_cri_cod) VALUES (1, 1), (2, 1), (3, 1), (4, 1);

SELECT * FROM crise_departamento;


-- Inserção na tabela "Boletim de Ocorrência"
INSERT INTO boletim (bol_ds, bol_dt_fato, bol_hora_fato, bol_dt_ini_atend, bol_hora_ini_atend, bol_dt_fim_atend, bol_hora_fim_atend, bol_pes_cod)
VALUES ('Perda dos Bens', '2015-09-11', '13:22', '2015-09-11', '13:32', '2015-09-11', '18:58', 1);

SELECT * FROM boletim;


-- Inserção na tabela "Histórico do Boletim de Ocorrência"
INSERT INTO histboletim (his_ds, his_dt_cad, his_bol_cod)
VALUES ('Devido ao alagamento, vítima perdeu todos os seus bens residenciais', '2015-09-11', 1),
('Vítima está pedindo abrigo junto aos orgãos públicos', '2015-09-12',1);

SELECT * FROM histboletim;


-- Inserção na tabela "Recursos"
INSERT INTO recurso (rec_nm, rec_tipo, rec_st, rec_loc_cod, rec_dep_cod)
VALUES ('Hospital Alfa', 'Público', 1, 1, 3);

SELECT * FROM recurso;


-- Inserção na tabela "Veículo"
INSERT INTO veiculo (vei_placa, vei_desc)
VALUES ('EPL1234', 'VW Gol Preto');

SELECT * FROM veiculo;


-- Inserção na tabela "Veículo Crise"
INSERT INTO veiculo_crise (vcr_vei_cod, vcr_cri_cod)
VALUES (1, 1);

SELECT * FROM veiculo_crise;


-- Inserção na tabela "Objeto"
INSERT INTO objeto (obj_tipo, obj_desc)
VALUES ('Eletrônico', 'Televisor 32 polegadas');

SELECT * FROM objeto;


-- Inserção na tabela "Objeto Crise"
INSERT INTO objeto_crise (obc_obj_cod, obc_cri_cod)
VALUES (1, 1);

SELECT * FROM objeto_crise;


SELECT TABLE_NAME, TABLE_ROWS
FROM INFORMATION_SCHEMA.TABLES
WHERE TABLE_SCHEMA = 'SIGAC'
