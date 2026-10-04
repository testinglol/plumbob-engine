
undefined4 FUN_004c3766(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int local_c;
  int local_8;
  
  piVar2 = param_4;
  piVar1 = param_1;
  *param_4 = 0;
  param_4[1] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  cVar3 = (**(code **)(*param_1 + 0x20))(0x40);
  if (cVar3 != '\0') {
    param_4 = (int *)0x0;
    param_1 = (int *)0x0;
    local_8 = 0;
    local_c = 0;
    FUN_004c3818(piVar1,param_2,param_3,&param_4,&param_1);
    FUN_004c3922(piVar1,param_2,param_3,param_4,param_1,&local_8,&local_c);
    *piVar2 = local_8;
    piVar2[1] = (int)param_4;
    piVar2[2] = local_c;
    piVar2[3] = (int)param_1;
    (**(code **)(*piVar1 + 0x24))(0x40);
  }
  if ((piVar2[2] + *piVar2 < param_2[2] - *param_2) &&
     (piVar2[1] + piVar2[3] < param_2[3] - param_2[1])) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

