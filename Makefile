CC = gc
CC_FLAGS = -Wall -Wextra

# temporary directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# generate target name from enclosing folder
TARGET = $(BINDIR)/$(shell basename `readlink -f .`)

CPP_FILES = $(wildcard $(SRCDIR)/*.c)

all: $(TARGET)

# notdir  	strip directory prefix
# :.c=.o	replace suffix
$(TARGET): $(addprefix $(OBJDIR)/, $(notdir $(CPP_FILES:.c=.o)))
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR) $(IMGDIR)
