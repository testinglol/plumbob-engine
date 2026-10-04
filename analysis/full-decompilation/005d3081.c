
undefined1 FUN_005d3081(undefined4 *param_1,code *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)param_1[1];
  for (puVar5 = (undefined4 *)*param_1; puVar5 != puVar1; puVar5 = puVar5 + 8) {
    cVar2 = (*param_2)(puVar5);
    if (cVar2 != '\0') break;
  }
  if (puVar5 == (undefined4 *)param_1[1]) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *param_3 = *puVar5;
      puVar5 = puVar5 + 1;
      param_3 = param_3 + 1;
    }
  }
  return uVar3;
}

