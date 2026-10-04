
undefined4 __thiscall FUN_005893b7(int *param_1,int param_2,short *param_3)

{
  char cVar1;
  int iVar2;
  short sVar3;
  short *psVar4;
  undefined4 local_8;
  
  local_8 = 0;
  if ((char)param_1[0x36] != '\0') {
    *(undefined1 *)(param_1 + 0x36) = 0;
    (**(code **)(*param_1 + 0x14))();
  }
  psVar4 = param_3;
  sVar3 = *param_3;
  if ((*(byte *)((int)param_3 + 5) & 4) == 0) {
    param_2 = FUN_005894e6();
  }
  else {
    if ((sVar3 < 0) || ((short)(ushort)*(byte *)(param_2 + 7) <= sVar3)) {
      param_3 = (short *)0x8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_3,&DAT_00698f30);
    }
    iVar2 = FUN_004752f8();
    sVar3 = *(short *)(iVar2 + sVar3 * 2);
    param_2 = FUN_00407498((int)*(short *)(param_2 + 4));
    psVar4 = param_3;
  }
  cVar1 = (char)psVar4[2];
  if (cVar1 == '\0') {
    if (param_2 == 0) {
      param_3 = (short *)0x17;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_3,&DAT_00698f30);
    }
    iVar2 = FUN_0047eda6();
    local_8 = FUN_0059dbf8(param_2,param_1[0x4e],(int)sVar3,'\x01' - (iVar2 != 0));
  }
  else if (cVar1 == '\x01') {
    local_8 = FUN_0059dd87(param_1[0x4e],(int)sVar3);
  }
  else if (cVar1 == '\x02') {
    local_8 = FUN_0059dd3f(param_1[0x4e],(int)sVar3);
  }
  else if (cVar1 == '\x03') {
    local_8 = FUN_0059dba1(param_1[0x4e],(int)sVar3);
  }
  return local_8;
}

