
void FUN_0044a7a2(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *local_c;
  undefined4 *local_8;
  
  for (local_8 = param_1; local_8 != param_2; local_8 = local_8 + 1) {
    uVar1 = *local_8;
    puVar2 = local_8;
    while( true ) {
      local_c = puVar2 + -1;
      cVar3 = (*param_4)(uVar1,*local_c);
      if (cVar3 == '\0') break;
      *puVar2 = *local_c;
      puVar2 = local_c;
    }
    *puVar2 = uVar1;
  }
  return;
}

