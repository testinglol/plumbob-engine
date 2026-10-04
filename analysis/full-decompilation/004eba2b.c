
void FUN_004eba2b(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  
  uVar2 = *param_2;
  cVar4 = (*param_4)(uVar2,*param_1);
  if (cVar4 == '\0') {
    while( true ) {
      uVar3 = param_2[-1];
      cVar4 = (*param_4)(uVar2,uVar3);
      if (cVar4 == '\0') break;
      *param_2 = uVar3;
      param_2 = param_2 + -1;
    }
    *param_2 = uVar2;
  }
  else {
    iVar6 = (int)param_2 - (int)param_1 >> 2;
    if (0 < iVar6) {
      puVar5 = param_2 + 1;
      do {
        puVar1 = (undefined4 *)((int)param_2 + (-4 - (int)(param_2 + 1)) + (int)puVar5);
        puVar5 = puVar5 + -1;
        iVar6 = iVar6 + -1;
        *puVar5 = *puVar1;
      } while (iVar6 != 0);
    }
    *param_1 = uVar2;
  }
  return;
}

