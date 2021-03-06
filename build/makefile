EXE=CFortranTranslator
CXX=g++

CFLAGS_NO = -fno-rtti -fno-exceptions 

NO_WARN = -Wno-unused-label -Wno-unused-variable -Wno-char-subscripts -Wno-unused-but-set-variable -Wno-unused-value 
NO_WARN_DEBUGING = -Wno-format-security -Wno-sign-compare -Wno-format-zero-length
CFLAGS = -Wall -DPOSIX -g -O3 -fpermissive -fPIC -std=c++17 $(NO_WARN) $(NO_WARN_DEBUGING)
OBJ_EXT = o

SRC_ROOT = ..
OBJ_ROOT = ./objs
OBJ_FOR90_ROOT = $(OBJ_ROOT)/for90std
OBJ_MAIN_ROOT = $(OBJ_ROOT)/src
OBJ_GRAMMAR_ROOT = $(OBJ_ROOT)/src/grammar
OBJ_PARSER_ROOT = $(OBJ_ROOT)/src/parser
OBJ_TARGET_ROOT = $(OBJ_ROOT)/src/target
EXE_ROOT = ../bin
GCOV_ROOT = $(OBJ_ROOT)

OBJ_FOR90 = $(OBJ_FOR90_ROOT)/farray.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/for90std.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forfilesys.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forlang.$(OBJ_EXT)    $(OBJ_FOR90_ROOT)/forstdio.$(OBJ_EXT)
OBJ_MAIN = $(OBJ_MAIN_ROOT)/develop.$(OBJ_EXT)    $(OBJ_MAIN_ROOT)/main.$(OBJ_EXT)     $(OBJ_MAIN_ROOT)/getopt2.$(OBJ_EXT)
OBJ_GRAMMAR = $(OBJ_GRAMMAR_ROOT)/simple_lexer.$(OBJ_EXT)    $(OBJ_GRAMMAR_ROOT)/for90.tab.$(OBJ_EXT)
OBJ_PARSER = $(OBJ_PARSER_ROOT)/attribute.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Function.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Intent.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/parser.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/tokenizer.$(OBJ_EXT)    $(OBJ_PARSER_ROOT)/Variable.$(OBJ_EXT)
OBJ_TARGET = $(OBJ_TARGET_ROOT)/gen_common.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_arraybuilder.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_attr_describer.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_callable.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_config.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_dimenslice.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_do.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_doc.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_exp.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_feature.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_function.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_if.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_io.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_label.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_paramtable.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_program.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_select.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_stmt.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_suite.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_type.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_vardef.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/gen_variable.$(OBJ_EXT)    $(OBJ_TARGET_ROOT)/lazygen.$(OBJ_EXT) 
OBJS = $(OBJ_FOR90) $(OBJ_MAIN) $(OBJ_GRAMMAR) $(OBJ_PARSER) $(OBJ_TARGET) 

GCOVS_T = $(patsubst %o,%gcov,$(OBJS))
GCOVS = $(patsubst $(OBJ_ROOT)%,$(GCOV_ROOT)%,$(GCOVS_T))

SRCS += $(wildcard $(SRC_ROOT)/for90std/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/src/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/src/grammar/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/src/parser/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/src/target/*.cpp)
SRCS += $(wildcard $(SRC_ROOT)/for90std/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/grammar/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/parser/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/target/*.h)
SRCS += $(wildcard $(SRC_ROOT)/src/grammar/*.y)

$(EXE): out $(EXE_ROOT)
	mv $(EXE) $(EXE_ROOT)/$(EXE)

out: CFLAGS_COV = 
out: make_dir gen_bison $(OBJS) 
	$(CXX) $(CFLAGS) -o $(EXE) $(OBJS) -L/usr/lib/ -lboost_system -lboost_exception

build_cov: CFLAGS_COV = -fprofile-arcs -ftest-coverage 
build_cov: make_dir gen_bison $(OBJS) 
	$(CXX) $(CFLAGS) $(CFLAGS_COV) --coverage -o $(EXE) $(OBJS) -L/usr/lib/ -lboost_system -lboost_exception


get_ans:
	python ../demos/merge_test.py ../demos/fortran/ ../demos/merge n
	python ../demos/merge_test.py ../demos/fortran77/ ../demos/merge y
	./CFortranTranslator -fF ../demos/merge.for.test
	python ../demos/merge_test.py ../demos/snippet/ ../demos/merge n
	./CFortranTranslator -fF ../demos/merge.for.test --tree 
	python ../demos/merge_test.py ../demos/error/ ../demos/merge n
	./CFortranTranslator -fF ../demos/merge.for.test

run_cov: get_ans
	gcov $(OBJ_GRAMMAR_ROOT)/for90.tab.cpp
	gcov -r -o $(OBJ_FOR90_ROOT)/*.gcno
	for name in `ls -al . | awk '{print $$NF}'| grep '.gcov$$' `;do mv $$name $(OBJ_FOR90_ROOT)/;done
	gcov -r -o $(OBJ_MAIN_ROOT)/*.gcno
	for name in `ls -al . | awk '{print $$NF}'| grep '.gcov$$' `;do mv $$name $(OBJ_MAIN_ROOT)/;done
	gcov -r -o $(OBJ_GRAMMAR_ROOT)/*.gcno 
	for name in `ls -al . | awk '{print $$NF}'| grep '.gcov$$' `;do mv $$name $(OBJ_GRAMMAR_ROOT)/;done
	gcov -r -o $(OBJ_PARSER_ROOT)/*.gcno
	for name in `ls -al . | awk '{print $$NF}'| grep '.gcov$$' `;do mv $$name $(OBJ_PARSER_ROOT)/;done
	gcov -r -o $(OBJ_TARGET_ROOT)/*.gcno
	for name in `ls -al . | awk '{print $$NF}'| grep '.gcov$$' `;do mv $$name $(OBJ_TARGET_ROOT)/;done

run_cov2: $(GCOVS)
$(GCOVS): get_ans
	gcov -r -o "$(patsubst $(GCOV_ROOT)%,$(OBJ_ROOT)%,$(@D))" "$(patsubst $(GCOV_ROOT)%,$(SRC_ROOT)%,$(@D))/$(patsubst %gcov,%cpp,$(@F))"
#	if [ -f "./$(@F)" ]; then mv "./$(@F)" $@; fi

run_lcov: $(OBJ_ROOT)
	lcov -c -o CFortranTranslator.lcov.info -d $(OBJ_ROOT)/
	genhtml CFortranTranslator.lcov.info -o CFortranTranslatorLCovHTML

run_coveralls_local: get_ans
	coveralls -b ./ -r ../ --exclude ./for90std --exclude ./src/grammar/for90.tab.cpp --exclude ./src/grammar/for90.flex.cpp --dryrun  --verbose --gcov-options '\-r'

run_coveralls: get_ans
	coveralls -b ./ -r ../ --exclude ./for90std --exclude ./src/grammar/for90.tab.cpp --exclude ./src/grammar/for90.flex.cpp --gcov-options '\-r'

tests: build_cov run_cov

$(OBJ_FOR90_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/for90std/%.cpp 
	$(CXX) -c $(CFLAGS) $(CFLAGS_COV) $< -o $@
$(OBJ_MAIN_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/src/%.cpp 
	$(CXX) -c $(CFLAGS) $(CFLAGS_COV) $< -o $@
$(OBJ_GRAMMAR_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/src/grammar/%.cpp 
	$(CXX) -c $(CFLAGS) $(CFLAGS_COV) $< -o $@
$(OBJ_GRAMMAR_ROOT)/for90.tab.$(OBJ_EXT): $(SRC_ROOT)/src/grammar/for90.tab.cpp 
	# this is work around, for errors only in travis ci(build 21)
	$(CXX) -c $(CFLAGS) $(CFLAGS_COV) $(SRC_ROOT)/src/grammar/for90.tab.cpp -o $(OBJ_GRAMMAR_ROOT)/for90.tab.$(OBJ_EXT)
$(OBJ_PARSER_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/src/parser/%.cpp 
	$(CXX) -c $(CFLAGS) $(CFLAGS_COV) $< -o $@
$(OBJ_TARGET_ROOT)/%.$(OBJ_EXT): $(SRC_ROOT)/src/target/%.cpp
	$(CXX) -c $(CFLAGS) $(CFLAGS_COV) $< -o $@

gen_bison: $(SRC_ROOT)/src/grammar/for90.y
	bison -d -v $(SRC_ROOT)/src/grammar/for90.y -o $(SRC_ROOT)/src/grammar/for90.tab.cpp


make_dir:
	mkdir -p $(EXE_ROOT)
	mkdir -p $(OBJ_FOR90_ROOT)
	mkdir -p $(OBJ_MAIN_ROOT)
	mkdir -p $(OBJ_GRAMMAR_ROOT)
	mkdir -p $(OBJ_PARSER_ROOT)
	mkdir -p $(OBJ_TARGET_ROOT)


.PHONY: clean_cov
clean_cov:
	find ./ -name "*.gcov" -delete
	rm -rf ./CFortranTranslatorLCovHTML

.PHONY: clean
clean:
	rm -rf $(OBJ_ROOT)
	find ./ -name "*.gcda" -delete
	find ./ -name "*.gcno" -delete