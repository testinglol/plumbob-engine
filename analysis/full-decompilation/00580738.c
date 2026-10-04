
int __fastcall FUN_00580738(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int local_c;
  int local_8;
  
  if ((int *)**(int **)(param_1 + 4) == *(int **)(param_1 + 4)) {
    local_8 = *(int *)(**(int **)(param_1 + 8) + 8);
    local_c = param_1;
    FUN_005807f5();
    FUN_00601324(&local_8);
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 4);
    local_c = 0;
    local_8 = param_1;
    FUN_00576b0a(*puVar1,puVar1,&local_c);
    iVar2 = FUN_005bc722(local_c);
    puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 4);
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar1 = (undefined4 *)*puVar1;
    }
    local_8 = puVar1[2];
    FUN_00580b0a(&local_c,puVar1);
    piVar3 = &local_8;
    while( true ) {
      FUN_00601324(piVar3);
      iVar2 = FUN_0060783f();
      if (iVar2 <= *(int *)(param_1 + 0xc)) break;
      local_c = *(int *)(**(int **)(param_1 + 8) + 8);
      FUN_005807f5();
      piVar3 = &local_c;
    }
  }
  return local_8;
}

