
void FUN_004ea2ce(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 uVar5;
  
  iVar3 = param_1 * 0x44 + DAT_006f2648;
  if (*(short *)(iVar3 + 4) == 0) {
    iVar1 = FUN_004e8d71(param_1);
    uVar5 = 0;
    do {
      uVar5 = FUN_00425b5f(uVar5);
      sVar4 = (short)uVar5;
      if (sVar4 == 0) break;
      iVar2 = FUN_0042573e((int)sVar4);
    } while ((iVar2 == 0) || (iVar2 = FUN_0045741b(), iVar2 != iVar1));
    *(short *)(iVar3 + 4) = sVar4;
  }
  FUN_0042573e((int)*(short *)(iVar3 + 4));
  return;
}

