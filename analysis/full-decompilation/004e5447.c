
undefined4
FUN_004e5447(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
            undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  cVar1 = FUN_004e5685(param_3,param_4);
  if (cVar1 != '\0') {
    uVar2 = FUN_0043856d(param_1,param_2,param_4[2] - *param_4,param_4[3] - param_4[1],0,0,param_5);
    FUN_004e586d(param_3);
  }
  return uVar2;
}

