
void __thiscall FUN_00464a5e(int *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_1[3];
  if (*(char *)((int)param_1 + 0x13) == '\0') {
    if (iVar3 == 2) {
      param_1[2] = param_1[2] + param_3 * 4;
    }
    else {
      if (iVar3 == 0) {
        puVar1 = (undefined4 *)(param_1[2] + *param_1);
        puVar2 = param_2;
      }
      else {
        puVar2 = (undefined4 *)(param_1[2] + *param_1);
        puVar1 = param_2;
      }
      if (0 < param_3) {
        do {
          if ((short)param_1[4] == 0) {
            *puVar2 = *puVar1;
          }
          else {
            *(undefined1 *)puVar2 = *(undefined1 *)((int)puVar1 + 3);
            *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar1 + 2);
            *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar1 + 1);
            *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)puVar1;
          }
          param_1[2] = param_1[2] + 4;
          puVar1 = puVar1 + 1;
          puVar2 = puVar2 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
  }
  else if ((iVar3 == 1) || (iVar3 == 2)) {
    iVar3 = param_3;
    puVar1 = param_2;
    if (0 < param_3) {
      do {
        param_2 = (undefined4 *)*puVar1;
        FUN_00464696(&param_2,&DAT_006e52a8);
        iVar3 = iVar3 + -1;
        puVar1 = puVar1 + 1;
      } while (iVar3 != 0);
    }
  }
  else {
    iVar3 = param_3;
    puVar1 = param_2;
    if (0 < param_3) {
      do {
        FUN_00464696(&param_2,&DAT_006e52a8);
        *puVar1 = param_2;
        iVar3 = iVar3 + -1;
        puVar1 = puVar1 + 1;
      } while (iVar3 != 0);
    }
  }
  return;
}

