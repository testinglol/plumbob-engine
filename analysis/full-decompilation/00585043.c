
void __thiscall FUN_00585043(int *param_1,int param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  
  if ((char)param_1[0x36] != '\0') {
    *(undefined1 *)(param_1 + 0x36) = 0;
    (**(code **)(*param_1 + 0x14))();
  }
  sVar1 = *param_3;
  if ((*(byte *)((int)param_3 + 5) & 4) != 0) {
    if ((sVar1 < 0) || ((short)(ushort)*(byte *)(param_2 + 7) <= sVar1)) {
      param_3 = (short *)0x8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_3,&DAT_00698f30);
    }
    iVar2 = FUN_004752f8();
    sVar1 = *(short *)(iVar2 + sVar1 * 2);
    iVar2 = FUN_00407498((int)*(short *)(param_2 + 4));
    if (iVar2 != 0) {
      if ((char)param_3[2] != '\0') {
        param_3 = (short *)0xc;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&param_3,&DAT_00698f30);
      }
      FUN_0059dce3(iVar2,param_1[1],(int)sVar1);
      return;
    }
  }
  param_3 = (short *)0x17;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&param_3,&DAT_00698f30);
}

