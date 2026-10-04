
void __fastcall FUN_0050b87b(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  if (cVar2 != '\0') {
    if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
      *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 0;
    }
    DAT_006fe838 = param_1[0x52];
    puVar1 = (undefined4 *)param_1[0x45];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    param_1[0x45] = 0;
    DAT_006f3604 = 0;
  }
  FUN_005e8e14();
  return;
}

