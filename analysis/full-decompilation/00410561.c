
void __thiscall FUN_00410561(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2;
  FUN_00464a4e(param_1 + 0x110,1);
  if (param_3 < 5) {
    FUN_00464d2c(param_1);
  }
  if (0 < param_3) {
    FUN_00464a4e(param_1 + 0x114,1);
  }
  if (1 < param_3) {
    FUN_00464a4e(param_1 + 0x118,1);
    FUN_00464a4e(param_1 + 0x11c,1);
    FUN_00464a4e(param_1 + 0x120,1);
  }
  if (param_3 < 7) {
    if (param_3 < 3) {
      *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) | 1;
    }
    else {
      FUN_0046494e((int)&param_2 + 3);
      *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) & 0xfffffffe;
      if (param_2._3_1_ != '\0') {
        *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) | 1;
      }
    }
    if (3 < param_3) {
      FUN_0046494e((int)&param_2 + 3);
      *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) & 0xfffffffd;
      if (param_2._3_1_ != '\0') {
        *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) | 2;
      }
    }
    if (5 < param_3) {
      FUN_0046494e((int)&param_2 + 3);
      *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) & 0xfffffffd;
      if (param_2._3_1_ != '\0') {
        *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) | 2;
      }
    }
  }
  else {
    FUN_00464a4e(param_1 + 0x138,1);
  }
  if (*(int *)(param_1 + 0x10c) != 0) {
    FUN_00410d4c(param_1 + 300,iVar1,param_3);
  }
  if (7 < param_3) {
    FUN_00464a4e(param_1 + 0x13c,1);
  }
  if (8 < param_3) {
    if ((*(int *)(iVar1 + 0xc) == 1) || (*(int *)(iVar1 + 0xc) == 2)) {
      FUN_00410b1a();
    }
    FUN_00464973(param_1 + 0x14e,6);
    if (*(int *)(iVar1 + 0xc) == 0) {
      *(undefined1 *)(param_1 + 0x14c) = 1;
    }
  }
  return;
}

