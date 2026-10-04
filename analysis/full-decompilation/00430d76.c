
void FUN_00430d76(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = param_1;
  if (param_1 != param_2) {
    do {
      param_1 = (undefined4 *)*puVar4;
      puVar2 = puVar4;
      while( true ) {
        puVar3 = puVar2 + -1;
        cVar1 = (*param_4)(&param_1,puVar3);
        if (cVar1 == '\0') break;
        *puVar2 = *puVar3;
        puVar2 = puVar3;
      }
      puVar4 = puVar4 + 1;
      *puVar2 = param_1;
    } while (puVar4 != param_2);
  }
  return;
}

