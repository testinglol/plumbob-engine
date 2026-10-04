
void FUN_005dbab7(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  FUN_005dbc40(param_1,param_2,0,0);
  for (puVar5 = param_2; puVar5 < param_3; puVar5 = puVar5 + 4) {
    if ((int)puVar5[2] < (int)param_1[2]) {
      uVar1 = *puVar5;
      uVar2 = puVar5[1];
      uVar3 = puVar5[2];
      uVar4 = puVar5[3];
      *puVar5 = *param_1;
      puVar5[1] = param_1[1];
      puVar5[2] = param_1[2];
      puVar5[3] = param_1[3];
      FUN_005dbc9d(param_1,0,(int)param_2 - (int)param_1 >> 4,uVar1,uVar2,uVar3,uVar4);
    }
  }
  FUN_005dbbe7(param_1,param_2);
  return;
}

