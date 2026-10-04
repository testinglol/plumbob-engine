
undefined4 __thiscall FUN_004329f3(int param_1,char *param_2)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (*param_2 != '\0') {
    if (*(int *)(param_2 + 0xc) != 0) {
      uVar3 = FUN_004328d2(*(undefined4 *)(param_2 + 0x10));
      return uVar3;
    }
    iVar1 = *(int *)(param_2 + 0x14);
    if ((0 < iVar1) && (iVar1 < 4)) {
      param_2 = (char *)CONCAT31(CONCAT12(param_2._3_1_,
                                          CONCAT11((char)iVar1,(char)(*(int *)(param_2 + 4) >> 4))),
                                 (char)(*(int *)(param_2 + 8) >> 4));
      sVar2 = FUN_004325af(&param_2);
      iVar1 = *(int *)(param_1 + 0xdc);
      uVar4 = (uint)sVar2;
      if ((int)uVar4 < 1) {
        return 0;
      }
      if ((*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x18) >> 2) + 1U <= uVar4) {
        return 0;
      }
      return *(undefined4 *)(*(int *)(iVar1 + 0x18) + -4 + uVar4 * 4);
    }
  }
  return 0;
}

