
void __fastcall FUN_00432396(int param_1)

{
  int iVar1;
  short sVar2;
  short sVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xdc) + 0x7c);
  sVar2 = *(short *)(iVar1 + 0x20) - *(short *)(param_1 + 0xa4);
  sVar3 = *(short *)(iVar1 + 0x1e) - *(short *)(param_1 + 0xa6);
  if ((short)(*(short *)(iVar1 + 0x12) - *(short *)(param_1 + 0xa8)) < 0) {
    sVar3 = sVar3 + -1;
  }
  if (sVar3 < 0) {
    sVar3 = sVar3 + 0xc;
    sVar2 = sVar2 + -1;
  }
  *(short *)(param_1 + 0x6e) = sVar2;
  *(short *)(param_1 + 0xaa) = sVar3 + sVar2 * 0xc;
  return;
}

