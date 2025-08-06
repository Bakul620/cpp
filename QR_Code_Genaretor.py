import qrcode
def qr_code_genarator():
    print("Enter the text or URL for the QR Code")
    st = input()
    qr = qrcode.make(st)
    qr.save("QR_Code.png")
    print("QR code saved as " + "QR_Code.png")

qr_code_genarator()