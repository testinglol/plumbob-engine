
undefined4 __thiscall FUN_00451baa(int param_1,int param_2,short *param_3)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  undefined4 uVar5;
  
  psVar2 = param_3;
  sVar1 = *param_3;
  if ((-1 < sVar1) && (sVar1 < 3)) {
    if (sVar1 == 0) {
      psVar4 = (short *)(uint)*(ushort *)(param_1 + 0xf0);
    }
    else if (sVar1 == 1) {
      psVar4 = (short *)(uint)*(ushort *)(param_2 + 4);
    }
    else {
      psVar4 = param_3;
      if (sVar1 == 2) {
        psVar4 = (short *)0x0;
      }
    }
    param_3 = (short *)FUN_00407498((int)(short)psVar4);
    if (param_3 == (short *)0x0) {
      uVar5 = 0;
    }
    else {
      FUN_00442db0(psVar4,CONCAT31((int3)((uint)param_3 >> 8),(byte)~*(byte *)(psVar2 + 1) >> 1) &
                          0xffffff01);
      iVar3 = FUN_006359f2(param_3,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor
                           ,0);
      if (iVar3 != 0) {
        FUN_00425ab3(iVar3);
      }
      if ((((short)psVar4 == *(short *)(param_1 + 0xf0)) && (DAT_006c4d5c != '\0')) &&
         ((*(byte *)(psVar2 + 1) & 1) == 0)) {
        uVar5 = 2;
      }
      else {
        uVar5 = 1;
      }
    }
    return uVar5;
  }
  param_3 = (short *)0x9;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&param_3,&DAT_00698f30);
}

