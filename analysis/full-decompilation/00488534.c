
void __thiscall FUN_00488534(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *(undefined1 *)param_1 = *(undefined1 *)param_2;
  *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
  *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
  iVar1 = 0xb;
  puVar2 = param_2;
  puVar3 = param_1;
  while( true ) {
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    *puVar3 = *puVar2;
  }
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  *(undefined1 *)(param_1 + 0xe) = *(undefined1 *)(param_2 + 0xe);
  *(undefined1 *)((int)param_1 + 0x39) = *(undefined1 *)((int)param_2 + 0x39);
  return;
}

