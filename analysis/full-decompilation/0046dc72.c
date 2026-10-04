
undefined4 __thiscall FUN_0046dc72(int param_1,short param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x1a4);
  while( true ) {
    if (puVar1 == *(undefined4 **)(param_1 + 0x1a4)) {
      return 0;
    }
    if (*(short *)(puVar1 + 2) == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  if ((puVar1[5] != 2) && (puVar1[5] != 3)) {
    return 0;
  }
  puVar3 = puVar1 + 2;
  puVar4 = param_3;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_0046ddb6(&param_2,puVar1);
  return 1;
}

