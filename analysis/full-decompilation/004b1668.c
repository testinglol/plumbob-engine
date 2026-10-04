
void __thiscall FUN_004b1668(int *param_1,char param_2,char param_3)

{
  if ((param_2 != *(char *)((int)param_1 + 0x51)) || (param_3 != '\0')) {
    *(char *)((int)param_1 + 0x51) = param_2;
    (**(code **)(*param_1 + 0x48))();
    *(undefined1 *)((int)param_1 + 0x4e) = 1;
    if ((DAT_006f2a08 != 0) && (*(int *)(DAT_006f2a08 + 0xb0) != 0)) {
      FUN_004cee86(0x80);
    }
  }
  return;
}

