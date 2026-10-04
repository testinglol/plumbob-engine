
bool FUN_005ed517(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_308;
  undefined4 local_307;
  undefined1 local_208;
  undefined4 local_207;
  undefined1 local_108;
  undefined4 local_107;
  undefined1 local_8;
  undefined2 local_7;
  
  local_8 = DAT_006de560;
  local_7 = 0;
  local_308 = DAT_006de560;
  puVar2 = &local_307;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  local_208 = DAT_006de560;
  puVar2 = &local_207;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  local_108 = DAT_006de560;
  puVar2 = &local_107;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  (*(code *)PTR_FUN_006d71dc)(*param_1,&local_8,&local_308,&local_208,&local_108);
  iVar1 = (*(code *)PTR__strlen_006d7028)(&local_108);
  FUN_005b8775(&local_108,iVar1);
  return iVar1 != 0;
}

