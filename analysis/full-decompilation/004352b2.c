
int __fastcall FUN_004352b2(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xdc) + 0x7c);
  iVar3 = (int)*(short *)(iVar1 + 0x1a) - (int)*(short *)(param_1 + 0x74);
  iVar2 = (int)*(short *)(iVar1 + 0x10) - (int)*(short *)(param_1 + 0x7a);
  iVar1 = FUN_00473661((int)*(short *)(iVar1 + 0x20),(int)*(short *)(iVar1 + 0x1e),
                       (int)*(short *)(iVar1 + 0x12),(int)*(short *)(param_1 + 0xa4),
                       (int)*(short *)(param_1 + 0xa6),(int)*(short *)(param_1 + 0xa8));
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0x3c;
    iVar2 = iVar2 + -1;
  }
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0x18;
    iVar1 = iVar1 + -1;
  }
  return (iVar2 + iVar1 * 0x18) * 0x3c + iVar3;
}

