
void FUN_004ce0bc(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar4 = param_1[-1];
    uVar1 = *param_1;
    puVar3 = param_1;
    while( true ) {
      cVar2 = (*param_4)(uVar1,uVar4);
      if (cVar2 == '\0') break;
      *puVar3 = puVar3[-1];
      uVar4 = puVar3[-2];
      puVar3 = puVar3 + -1;
    }
    *puVar3 = uVar1;
  }
  return;
}

