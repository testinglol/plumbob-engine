
void FUN_0048c34e(undefined2 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_006e5790;
  if (DAT_006e5790 != DAT_006e5794) {
    while ((undefined2 *)*puVar2 != param_1) {
      puVar2 = puVar2 + 1;
      if (puVar2 == DAT_006e5794) {
        return;
      }
    }
    FUN_005db2f2(puVar2);
    if ((*(int *)(param_1 + 6) != 0) && (cVar1 = FUN_00432644(), cVar1 == '\0')) {
      FUN_0044127f(*param_1);
      *(undefined4 *)(param_1 + 6) = 0;
    }
    FUN_006321f0(param_1);
  }
  return;
}

