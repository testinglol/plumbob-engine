
void FUN_00501e85(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *puVar4;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = *param_1;
    puVar2 = param_1;
    while( true ) {
      puVar4 = puVar2 + -1;
      cVar3 = FUN_00501cfd(uVar1,*puVar4);
      if (cVar3 == '\0') break;
      *puVar2 = *puVar4;
      puVar2 = puVar4;
    }
    *puVar2 = uVar1;
  }
  return;
}

