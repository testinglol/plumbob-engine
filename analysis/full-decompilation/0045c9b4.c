
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0045c9b4(int param_1,int param_2,short *param_3,int *param_4,int *param_5,int *param_6,
            float *param_7)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float10 fVar5;
  int local_10;
  int local_c;
  
  sVar1 = *param_3;
  if (sVar1 == 2) {
    fVar5 = (float10)_DAT_00666c18;
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
  }
  else {
    if (sVar1 == 0) {
      iVar3 = FUN_00407498((int)*(short *)(param_2 + 4));
      *param_4 = iVar3;
      if (iVar3 == 0) {
        return 0;
      }
      FUN_0043270d(iVar3);
      *param_5 = local_10;
      piVar4 = param_5;
    }
    else {
      if (sVar1 != 1) {
        return 0;
      }
      iVar3 = FUN_00407498((int)*(short *)(param_2 + 4));
      piVar4 = param_5;
      *param_5 = iVar3;
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24;
      if (iVar3 == 1 || iVar3 + -1 < 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x130) + 0x24;
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_00407498((int)*(short *)(iVar3 + 0x10));
      }
      *param_4 = iVar3;
      if ((param_3[2] < 0) || ((short)(ushort)*(byte *)(param_2 + 7) <= param_3[2])) {
        param_5 = (int *)0x8;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&param_5,&DAT_00698f30);
      }
      iVar3 = FUN_004752f8();
      local_c = (int)*(short *)(iVar3 + param_3[2] * 2);
    }
    *param_6 = local_c;
    iVar3 = *piVar4;
    if (iVar3 == 0) {
      fVar5 = (float10)0;
    }
    else {
      iVar2 = *param_6;
      if ((iVar2 < 0) || ((*(int *)(iVar3 + 0x134) - *(int *)(iVar3 + 0x130)) / 0x24 + -1 <= iVar2))
      {
        return 0;
      }
      fVar5 = (float10)FUN_004340f2(iVar2);
      param_5 = (int *)(float)fVar5;
      fVar5 = (float10)FUN_00454f69(&param_5);
      fVar5 = fVar5 * (float10)_DAT_00667344;
    }
  }
  *param_7 = (float)fVar5;
  return 1;
}

