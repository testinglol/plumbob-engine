
void FUN_005c7200(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != param_2) {
    puVar1 = param_3 + 4;
    puVar2 = param_1 + 4;
    do {
      if (puVar1 != (undefined4 *)0x10) {
        *param_3 = *param_1;
        puVar1[-3] = puVar2[-3];
        puVar1[-2] = puVar2[-2];
        puVar1[-1] = puVar2[-1];
        *puVar1 = *puVar2;
        *(undefined2 *)(puVar1 + 1) = *(undefined2 *)(puVar2 + 1);
      }
      param_1 = param_1 + 6;
      puVar2 = puVar2 + 6;
      param_3 = param_3 + 6;
      puVar1 = puVar1 + 6;
    } while (param_1 != param_2);
  }
  return;
}

