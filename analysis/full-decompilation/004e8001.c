
bool FUN_004e8001(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = 0;
    FUN_00436a50(4);
    cVar2 = (**(code **)(iVar1 + 0xc))(200,200,extraout_var,extraout_var_00,uVar3,uVar4,uVar5);
    if (cVar2 != '\0') {
      cVar2 = FUN_005df69e();
      if (cVar2 != '\0') goto LAB_004e8043;
    }
    (**(code **)*param_1)(1);
    param_1 = (int *)0x0;
  }
LAB_004e8043:
  return param_1 != (int *)0x0;
}

