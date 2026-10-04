
void FUN_00493f10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0xd) {
    if (param_3 != (undefined4 *)0x0) {
      *(undefined1 *)param_3 = *(undefined1 *)param_1;
      *(undefined1 *)((int)param_3 + 1) = *(undefined1 *)((int)param_1 + 1);
      *(undefined1 *)((int)param_3 + 2) = *(undefined1 *)((int)param_1 + 2);
      iVar1 = 0xb;
      puVar2 = param_1;
      puVar3 = param_3;
      while( true ) {
        puVar3 = puVar3 + 1;
        puVar2 = puVar2 + 1;
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        *puVar3 = *puVar2;
      }
      param_3[0xc] = param_1[0xc];
    }
    param_3 = param_3 + 0xd;
  }
  return;
}

