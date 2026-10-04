
void __thiscall FUN_0056778c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10c);
  if (iVar1 < 0x41) {
    if (((iVar1 == 0x40) || (iVar1 == 2)) || ((iVar1 == 4 || ((iVar1 == 8 || (iVar1 == 0x20)))))) {
LAB_0056782b:
      FUN_005e46f0(0);
    }
  }
  else if ((((iVar1 == 0x80) || (iVar1 == 0x100)) || (iVar1 == 0x200)) || (iVar1 == 0x400))
  goto LAB_0056782b;
  switch(param_2) {
  case 0:
    FUN_0056727c(0x20);
    break;
  case 1:
    FUN_0056727c(8);
    break;
  case 2:
    FUN_0056727c(4);
    break;
  case 3:
    FUN_0056727c(2);
    break;
  case 4:
    FUN_0056727c(0x40);
    break;
  case 5:
    FUN_0056727c(0x80);
    break;
  case 6:
    FUN_0056727c(0x100);
    break;
  case 7:
    FUN_0056727c(0x200);
    break;
  case 8:
    FUN_0056727c(0x400);
    break;
  default:
    goto LAB_005678f8;
  }
  FUN_005e46f0(1);
LAB_005678f8:
  return;
}

