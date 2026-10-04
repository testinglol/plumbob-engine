
uint FUN_004c8728(short *param_1,short *param_2,int *param_3)

{
  short sVar1;
  short sVar2;
  undefined4 in_EAX;
  undefined4 uVar3;
  int iVar5;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)in_EAX >> 0x10);
  uVar3 = CONCAT22(uVar4,*param_2);
  if ((*param_2 < param_1[2]) && (param_2[1] < param_1[3])) {
    sVar1 = param_1[1];
    uVar3 = CONCAT22(uVar4,sVar1);
    if ((sVar1 < param_2[3]) && (*param_1 < param_2[2])) {
      iVar5 = (int)sVar1 - (int)param_2[1];
      *param_3 = iVar5;
      if (iVar5 < 0) {
        *param_3 = 0;
      }
      sVar1 = param_2[3];
      sVar2 = param_1[3];
      param_3[2] = (int)sVar1 - (int)sVar2;
      if ((int)sVar1 - (int)sVar2 < 0) {
        param_3[2] = 0;
      }
      sVar1 = *param_1;
      sVar2 = *param_2;
      param_3[1] = (int)sVar1 - (int)sVar2;
      if ((int)sVar1 - (int)sVar2 < 0) {
        param_3[1] = 0;
      }
      sVar1 = param_2[2];
      sVar2 = param_1[2];
      param_3[3] = (int)sVar1 - (int)sVar2;
      if ((int)sVar1 - (int)sVar2 < 0) {
        param_3[3] = 0;
      }
      return (uint)param_3 & 0xffffff00;
    }
  }
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}

