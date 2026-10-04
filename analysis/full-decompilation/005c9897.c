
void __thiscall FUN_005c9897(int param_1,LPPOINT param_2)

{
  tagRECT local_14;
  
  if (*(char *)(param_1 + 8) == '\0') {
    GetClientRect(*(HWND *)(param_1 + 300),&local_14);
    param_2->x = local_14.left;
    param_2->y = local_14.top;
    ClientToScreen(*(HWND *)(param_1 + 300),param_2);
  }
  else {
    param_2->x = 0;
    param_2->y = 0;
  }
  return;
}

