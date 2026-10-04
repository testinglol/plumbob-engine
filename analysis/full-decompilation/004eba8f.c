
void FUN_004eba8f(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  for (puVar6 = param_1; puVar6 != param_2; puVar6 = puVar6 + 1) {
    uVar1 = *puVar6;
    cVar3 = (*param_4)(uVar1,puVar6[-1]);
    param_1 = puVar6;
    if (cVar3 != '\0') {
      uVar4 = puVar6[-1];
      puVar2 = puVar6 + -1;
      do {
        puVar5 = puVar2;
        *param_1 = uVar4;
        uVar4 = puVar5[-1];
        cVar3 = (*param_4)(uVar1,uVar4);
        puVar2 = puVar5 + -1;
        param_1 = puVar5;
      } while (cVar3 != '\0');
    }
    *param_1 = uVar1;
  }
  return;
}

