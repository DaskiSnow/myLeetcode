SRCS := $(wildcard *.cc)
#EXES := 
EXES := $(patsubst %.cc, %, $(SRCS)) # $(SRCS: %.cc=%) 

CC := g++
CFLAGS := -Wall -g -std=c++11 #-lpthread  #-fsanitize=leak
#开启内存泄露检查功能：-fsanitize=leak
#开启地址越界检查功能：-fsanitize=address
#开启越界详细错误信息：-fno-omit-frame-pointer
#-llog4cpp  
# 取消编译器优化 -fno-elide-constructors

.PHONY: out clean rebulid

out: $(EXES)

%:%.cc
	$(CC) $< -o $@ $(CFLAGS)

clean:
	$(RM) $(EXES)

rebulid: clean out
