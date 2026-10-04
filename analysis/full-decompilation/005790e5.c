
void __fastcall FUN_005790e5(undefined4 *param_1)

{
  CParkingWnd *this;
  int iVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_00671734;
  param_1 = param_1 + 0x11;
  iVar2 = 0x40;
  do {
    iVar1 = 0x40;
    do {
      this = (CParkingWnd *)*param_1;
      if (this != (CParkingWnd *)0x0) {
        CParkingWnd::~CParkingWnd(this);
        FUN_006321f0(this);
      }
      *param_1 = 0;
      param_1 = param_1 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

