
void __thiscall FUN_005db182(int param_1,int param_2,int *param_3)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x1c4) == 0) {
LAB_005db1ba:
    if (param_2 == *(int *)(param_1 + 0x218)) goto LAB_005db1ca;
  }
  else {
    if (*(char *)(param_1 + 0x1c8) == '\0') {
      cVar1 = (**(code **)(*param_3 + 0x8c))(0x20000);
      if (cVar1 == '\0') goto LAB_005db1ba;
    }
    param_2 = *(int *)(param_1 + 0x1c4);
  }
  *(int *)(param_1 + 0x218) = param_2;
LAB_005db1ca:
  if (*(int *)(param_1 + 0x218) != 0) {
    FUN_005e73da();
    *(undefined1 *)(param_1 + 0x1e1) = 1;
  }
  return;
}

