
uint __thiscall FUN_005117ea(uint param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 local_2c;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  pcVar2 = s_Magic___Has_Made_Spell_Recipe__006cc988;
  puVar3 = &local_2c;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x108);
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  if (iVar1 == 0) {
    param_1 = param_1 & 0xffffff00;
  }
  else {
    local_c = param_3;
    local_8 = 0;
    local_a = param_2;
    local_6 = 0;
    param_1 = FUN_00452c2d(*(undefined4 *)(*(int *)(iVar1 + 0x11c) + 0xc),
                           *(undefined2 *)(iVar1 + 0xf0),&local_2c,&local_c);
  }
  return param_1;
}

