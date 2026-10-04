
undefined4 * FUN_0053d3e3(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *local_8;
  
  puVar2 = param_3;
  if ((param_1 != param_2) && (puVar2 = param_1, param_3 != param_2)) {
    local_8 = param_1;
    puVar2 = param_2;
    while ((local_8 != puVar2 && (puVar2 = puVar2 + -1, local_8 != puVar2))) {
      uVar1 = *local_8;
      *local_8 = *puVar2;
      *puVar2 = uVar1;
      local_8 = local_8 + 1;
    }
    local_8 = param_2;
    puVar2 = param_3;
    while ((local_8 != puVar2 && (puVar2 = puVar2 + -1, local_8 != puVar2))) {
      uVar1 = *local_8;
      *local_8 = *puVar2;
      *puVar2 = uVar1;
      local_8 = local_8 + 1;
    }
    do {
      if (param_2 == param_3) break;
      puVar2 = param_1 + 1;
      param_3 = param_3 + -1;
      uVar1 = *param_1;
      *param_1 = *param_3;
      *param_3 = uVar1;
      param_1 = puVar2;
    } while (puVar2 != param_2);
    puVar3 = param_3;
    puVar4 = param_1;
    if (param_1 == param_2) {
      for (; (puVar2 = param_3, param_2 != puVar3 && (puVar3 = puVar3 + -1, param_2 != puVar3));
          param_2 = param_2 + 1) {
        uVar1 = *param_2;
        *param_2 = *puVar3;
        *puVar3 = uVar1;
      }
    }
    else {
      do {
        param_2 = param_2 + -1;
        if (puVar4 == param_2) {
          return param_1;
        }
        puVar3 = puVar4 + 1;
        uVar1 = *puVar4;
        *puVar4 = *param_2;
        *param_2 = uVar1;
        puVar2 = param_1;
        puVar4 = puVar3;
      } while (puVar3 != param_2);
    }
  }
  return puVar2;
}

