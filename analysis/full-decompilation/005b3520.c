
void FUN_005b3520(int *param_1,byte *param_2)

{
  byte bVar1;
  
  bVar1 = 0;
  if (*param_1 < DAT_00703f1c) {
    bVar1 = 0x10;
  }
  else if (DAT_00703f0c < *param_1) {
    bVar1 = 0x20;
  }
  if (param_1[1] < DAT_00703f18) {
    bVar1 = bVar1 | 4;
  }
  else if (DAT_00703ef8 < param_1[1]) {
    bVar1 = bVar1 | 8;
  }
  if (param_1[3] < 0) {
    bVar1 = bVar1 ^ 0x3d;
  }
  else {
    if (DAT_00703efc < param_1[3]) {
      *param_2 = bVar1 | 1;
      return;
    }
    if (DAT_00703f08 <= param_1[2]) {
      *param_2 = bVar1 | 2;
      return;
    }
  }
  *param_2 = bVar1;
  return;
}

