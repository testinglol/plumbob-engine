
void FUN_0044a640(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 code *param_5)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *local_8;
  
  FUN_0044a87f(param_1,param_2,param_5,0,0);
  for (local_8 = param_2; local_8 < param_3; local_8 = local_8 + 1) {
    cVar2 = (*param_5)(*local_8,*param_1);
    if (cVar2 != '\0') {
      uVar1 = *local_8;
      *local_8 = *param_1;
      FUN_0044a8e4(param_1,0,(int)param_2 - (int)param_1 >> 2,uVar1,param_5);
    }
  }
  FUN_0044a819(param_1,param_2,param_5);
  return;
}

