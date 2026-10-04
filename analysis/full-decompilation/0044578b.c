
void __thiscall FUN_0044578b(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  short *psVar6;
  
  iVar2 = FUN_00407498(param_2);
  if (iVar2 != 0) {
    iVar2 = FUN_004750ba();
    uVar3 = (uint)*(ushort *)(iVar2 + 2);
    uVar4 = FUN_004754d8(uVar3);
    puVar5 = (ushort *)FUN_004020a6(uVar4,uVar3);
    if ((puVar5 != (ushort *)0x0) && ((*puVar5 & 0x7fff) == 0)) {
      sVar1 = (short)*(undefined4 *)(*(int *)(param_1 + 0x24) + -4 + param_2 * 4);
      if (-1 < sVar1) {
        psVar6 = (short *)FUN_004752f8();
        *psVar6 = sVar1;
      }
    }
  }
  FUN_00431e78(param_2,0xfffffffe);
  return;
}

