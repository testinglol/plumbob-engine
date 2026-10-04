
undefined4 __thiscall FUN_0046bd76(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  
  iVar2 = 0;
  iVar1 = *(int *)(param_2 + 8);
  sVar4 = 0;
  iVar5 = -1;
  if (iVar1 != 0) {
    FUN_004573f9();
    iVar2 = FUN_0045741b();
    sVar4 = *(short *)(iVar1 + 0xf0);
    iVar5 = *(int *)(param_2 + 0x10);
  }
  if (((iVar2 == *(int *)(param_1 + 8)) && (sVar4 == *(short *)(param_1 + 0xc))) &&
     (iVar5 == *(int *)(param_1 + 0x10))) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

