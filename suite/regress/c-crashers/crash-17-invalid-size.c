#include <keystone/keystone.h>
int main(int argc, char **argv) {
  int ks_arch = KS_ARCH_ARM, ks_mode = KS_MODE_LITTLE_ENDIAN;
  unsigned char assembly[] = {
    'L', 'D', 'r', ' ', 'A', 'H', '1', 'I', ',', '=',
    'j', 'H', 'G', 'Q', ',', '=', '2', ',', '=', 'r',
    ',', '=', 'G', 'Q', ',', '=', '1', '1', '1', '1',
    '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
    '1', '2', ',', '=', 'e', 'y', ',', '=', '2', ',',
    '=', 'e', 'Q', ',', '=', 'r', 'Q', ',', '=', 'r',
    ',', '=', 0x00,
  };
  ks_engine *ks;
  ks_err err = ks_open(ks_arch, ks_mode, &ks);
  if (!err) {
    size_t count, size;
    unsigned char *insn;
    ks_asm(ks, (char *)assembly, 0, &insn, &size, &count);
    ks_free(insn);
  }
  ks_close(ks);
}
