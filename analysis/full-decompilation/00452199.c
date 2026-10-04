
undefined4 FUN_00452199(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  
  iVar1 = FUN_00407498((int)*(short *)(param_1 + 4));
  if (iVar1 == 0) {
    param_1 = 0x15;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_1,&DAT_00698f30);
  }
  iVar2 = FUN_004750ba();
  if (iVar2 != 0) {
    uVar3 = (uint)*(ushort *)(iVar2 + 2);
    uVar4 = FUN_004754d8(uVar3);
    puVar5 = (ushort *)FUN_004020a6(uVar4,uVar3);
    if (puVar5 != (ushort *)0x0) {
      if ((*puVar5 & 0x7fff) == 0) {
        puVar6 = (undefined2 *)FUN_004752f8();
        *puVar6 = 0;
        FUN_00431e78((int)*(short *)(iVar1 + 0xf0),0);
      }
      else if ((*puVar5 & 0x7fff) == 0x11) {
        puVar6 = (undefined2 *)FUN_004752f8();
        *puVar6 = 0;
      }
    }
  }
  return 1;
}

