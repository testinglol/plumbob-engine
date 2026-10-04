
void __fastcall FUN_005ec165(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = (**(code **)(*(int *)(param_1[0x1e] + 0x48) + 0x18))();
  iVar1 = param_1[0x24];
  iVar3 = *param_1;
  if (cVar2 != '\0') {
    cVar2 = (**(code **)(iVar3 + 0x11c))((char)iVar1);
    if (cVar2 != '\0') {
      return;
    }
    iVar3 = *param_1;
  }
  (**(code **)(iVar3 + 0x128))((char)iVar1);
  return;
}

