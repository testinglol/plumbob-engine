
void FUN_00501e20(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar2 = *param_2;
  cVar3 = FUN_00501cfd(uVar2,*param_1);
  if (cVar3 == '\0') {
    while( true ) {
      puVar4 = param_2 + -1;
      cVar3 = FUN_00501cfd(uVar2,*puVar4);
      param_1 = param_2;
      if (cVar3 == '\0') break;
      *param_2 = *puVar4;
      param_2 = puVar4;
    }
  }
  else {
    iVar5 = (int)param_2 - (int)param_1 >> 2;
    if (0 < iVar5) {
      puVar4 = param_2 + 1;
      do {
        puVar1 = (undefined4 *)((int)param_2 + (-4 - (int)(param_2 + 1)) + (int)puVar4);
        puVar4 = puVar4 + -1;
        iVar5 = iVar5 + -1;
        *puVar4 = *puVar1;
      } while (iVar5 != 0);
    }
  }
  *param_1 = uVar2;
  return;
}

