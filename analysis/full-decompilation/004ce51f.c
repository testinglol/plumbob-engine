
void __thiscall FUN_004ce51f(int param_1,char param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_004733e4(DAT_006e5490);
    FUN_004733e4(DAT_006e5490);
    if (param_2 == '\0') {
      iVar1 = FUN_00473417();
      if (iVar1 != 0) {
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1;
      }
      iVar1 = FUN_00473417();
      if (iVar1 != 0) {
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x6078000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_004ce5de(*(int *)(param_1 + 0xc));
      FUN_0050a9c0(param_1);
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x14) = DAT_006e5490;
    }
  }
  return;
}

