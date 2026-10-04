
void __thiscall FUN_004d3356(int param_1,char param_2,char param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x189) != '\0') {
    FUN_005dae65(param_1);
    *(undefined1 *)(param_1 + 0x189) = 0;
  }
  *(char *)(param_1 + 0x188) = param_2;
  if ((param_2 != '\0') && (param_3 != '\0')) {
    FUN_005dadff(param_1,*(undefined4 *)(param_1 + 0x198),0);
    *(undefined1 *)(param_1 + 0x189) = 1;
  }
  if (*(int **)(param_1 + 0x184) != (int *)0x0) {
    iVar1 = **(int **)(param_1 + 0x184);
    if (*(char *)(param_1 + 0x188) == '\0') {
      (**(code **)(iVar1 + 0x98))();
    }
    else {
      (**(code **)(iVar1 + 0x94))();
    }
  }
  return;
}

