
void FUN_00430d0a(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = param_2;
  puVar6 = param_1;
  param_2 = (undefined4 *)*param_2;
  cVar2 = (*param_4)(&param_2,param_1);
  if (cVar2 == '\0') {
    param_1 = param_2;
    puVar6 = puVar5;
    while( true ) {
      puVar5 = puVar6 + -1;
      cVar2 = (*param_4)(&param_1,puVar5);
      if (cVar2 == '\0') break;
      *puVar6 = *puVar5;
      puVar6 = puVar5;
    }
  }
  else {
    iVar4 = (int)puVar5 - (int)puVar6 >> 2;
    param_1 = param_2;
    if (0 < iVar4) {
      puVar3 = puVar5 + 1;
      do {
        puVar1 = (undefined4 *)((int)puVar5 + (-4 - (int)(puVar5 + 1)) + (int)puVar3);
        puVar3 = puVar3 + -1;
        iVar4 = iVar4 + -1;
        *puVar3 = *puVar1;
      } while (iVar4 != 0);
    }
  }
  *puVar6 = param_1;
  return;
}

