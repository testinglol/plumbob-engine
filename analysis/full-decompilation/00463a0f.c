
undefined4 FUN_00463a0f(int param_1,int param_2)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  
  sVar2 = *(short *)(param_2 + 0x56);
  if (sVar2 == 0) {
    sVar2 = FUN_00463970(param_1);
    *(short *)(param_2 + 0x56) = sVar2;
  }
  uVar1 = DAT_00667478;
  for (iVar3 = *(int *)(param_1 + 0x90); iVar3 != *(int *)(param_1 + 0x94); iVar3 = iVar3 + 4) {
    FUN_00463155(sVar2,uVar1);
  }
  return 1;
}

